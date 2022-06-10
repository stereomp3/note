import pandas as pd
import numpy as np
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer
from sklearn import metrics
from sklearn.svm import SVC
import customTransfer
from sklearn.model_selection import StratifiedShuffleSplit  # 使用Cross-validation
from sklearn.metrics import f1_score  # 調和平均值F1
from sklearn.preprocessing import LabelEncoder
import matplotlib.pyplot as plt
from sklearn.ensemble import BaggingClassifier

data = pd.read_csv('../data/wdbc.csv')
# 良性 = 0, 惡性 = 1，AUC需要用到數字
le = LabelEncoder()
for col in data[['Diagnosis']]:
    data[col] = le.fit_transform(data[col])

Y_test = data[["Diagnosis"]]

num_pipeline = Pipeline([
    ('imputer', SimpleImputer(strategy="median")),
    ('attribs_adder', customTransfer.CombineAttributesAdder()),
    ('std_scaler', StandardScaler()),
])

cat_attribs = ["Diagnosis"]
data_num = data.drop("Diagnosis", axis=1)
num_attribs = list(data_num)

full_pipeline = ColumnTransformer([
    ("num", num_pipeline, num_attribs),
    ("cat", OneHotEncoder(), cat_attribs),
])
data_prepare = full_pipeline.fit_transform(data)

# 使用Cross-validation
split = StratifiedShuffleSplit(n_splits=10, test_size=0.2, random_state=42)
strat_train_set = np.c_
for train_index, test_index in split.split(data, Y_test):
    strat_train_set = data.loc[train_index]
    strat_test_set = data.loc[test_index]

# BAGGING
mod_dt = BaggingClassifier(base_estimator=SVC(), n_estimators=10)

mod_dt.fit(data_prepare, np.ravel(Y_test))
prediction = mod_dt.predict(data_prepare)  # 產生測試模型
confusion = metrics.confusion_matrix(Y_test, prediction)  # confuse matrix

# accuracy
print('The accuracy of the BAGGING is', "{:.3f}".format(metrics.accuracy_score(prediction, Y_test)))

# precision
print('The precision of the BAGGING is', "{:.3f}".format(metrics.precision_score(prediction, Y_test)))

# recall
print('The recall of the BAGGING is', "{:.3f}".format(metrics.recall_score(prediction, Y_test)))

# f1 score
res = f1_score(Y_test, prediction)
print('The f1_score of the BAGGING is', "{:.3f}".format(res))

# sensitivity
sensitivity = confusion[0, 0] / (confusion[0, 0] + confusion[0, 1])
print('The sensitivity of the BAGGING is', "{:.3f}".format(sensitivity))

# specificity
specificity = confusion[1, 1] / (confusion[1, 0] + confusion[1, 1])
print('The specificity of the BAGGING is', "{:.3f}".format(specificity))

# auc
print('The roc_auc_score of the BAGGING is', "{:.3f}".format(metrics.roc_auc_score(prediction, Y_test)))

# draw confusion matrix
plt.figure("Confusion Matrix")
plt.imshow(confusion, cmap="Blues")
indices = range(len(confusion))
plt.xticks(indices, rotation=-60, fontsize=12)  # 設定文字
plt.yticks(indices, fontsize=12)  # 設定文字
plt.colorbar()
plt.xlabel('prediction label')
plt.ylabel('true label')
plt.title('Confusion Matrix')

for first_index in range(len(confusion)):
    for second_index in range(len(confusion[first_index])):
        if first_index == 0 and second_index == 0:
            plt.text(first_index, second_index, confusion[first_index][second_index], color='white')
        else:
            plt.text(first_index, second_index, confusion[first_index][second_index])

# draw ROC curve
FPR, TPR, thresholds = metrics.roc_curve(Y_test, prediction, pos_label=None, sample_weight=None)
auc_score = metrics.roc_auc_score(Y_test, prediction, average='macro', sample_weight=None)

plt.figure("ROC Curve")
plt.title("ROC Curve")
plt.xlabel('False Positive Rate')  # FPR = FP / (FP + TN)
plt.ylabel('True Positive Rate')  # TPR = TP / (TP + FN)
plt.plot(FPR, TPR, 'b', label='AUC = %0.2f' % auc_score)
plt.legend(loc='lower right')
plt.plot([0, 1], [0, 1], 'r--')
plt.xlim([-0.1, 1.1])
plt.ylim([-0.1, 1.1])

# draw PR curve
precision, recall, thresholds = metrics.precision_recall_curve(Y_test, prediction, pos_label=None, sample_weight=None)
plt.figure("P-R Curve")
plt.title("Precision/Recall Curve")
plt.xlabel('Recall')  # Recall = TP/(TP+FN)
plt.ylabel('Precision')  # Precision = TP/(TP+FP)

plt.plot(recall, precision)

plt.show()
