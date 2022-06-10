# AD FINAL TERM 

使用Caret資料集，分類良性腫瘤及惡性腫瘤，挑選 scikit-learn 中的3種分類方法進行比較。 

參考資料集: [UCI Machine Learning Repository: Breast Cancer Wisconsin (Diagnostic) Data Set](http://archive.ics.uci.edu/ml/datasets/breast+cancer+wisconsin+(diagnostic))



## Question

1. 資料集分割及訓練方式 訓練及測試集為80%，20%，採用CV=10，RandomState=42。
2. 計算分類指標 
   1. Accuracy 
   2. Precision 
   3. Recall 
   4. F1 score 
   5. Sensitivity TPR = TP / (TP + FN)，在所有實際為陽性的樣本中，被正確地判斷為陽性之比率
   6. Specificity FPR = FP / (FP + TN)，在所有實際為陰性的樣本中，被錯誤地判斷為陽性之比率
   7. ROC AUC
3. condition: 
   1. 至少有一種方法精確率(Accuracy)要達到 >= 97%
   2. 繳交程式(github url or upload file)及執行結果畫面



## Answer 

在各個資料夾都有附上python的檔案

| title                            | content                                                      |
| -------------------------------- | ------------------------------------------------------------ |
| [**INTRODUCTION**](INTRODUCTION) | [Tuning Model](INTRODUCTION#Tuning Model)<ul><li>[LabelEncoder](110semester02/01.md#使用Centos的好處)</li><li> [Pipeline](110semester02/01.md#virtulBox安裝教學)</li></ul> |
| [KNN](KNN)                       |                                                              |
| [BernoulliNB](BernoulliNB)       |                                                              |
| [Bagging](Bagging)               |                                                              |

