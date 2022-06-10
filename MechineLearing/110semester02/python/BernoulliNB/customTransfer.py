"""
    撰寫轉換器的技巧
    原本是使用week09的方法加入新的column，現在使用函式包裝
    多加上幾個變數
    可以使用不同的X去組合新的屬性，讓模型有更高的準確率
"""
import pandas as pd
import numpy as np
from sklearn.base import BaseEstimator, TransformerMixin

data = pd.read_csv('../data/wdbc.csv')
X1, X2, X3, X4 = 3, 4, 5, 6


# 把新增的屬性套成函式，讓他自動執行
class CombineAttributesAdder(BaseEstimator, TransformerMixin):
    def fit(self, X, y=None):
        return self  ## nothing else to do

    def transform(self, X, y=None):
        # 針對二維數據np.array [:, 0] 代表取第0個col，[:, 1] 代表取第1個col...
        new_label1 = X[:, X1] / X[:, X4]
        new_label2 = X[:, X3] / X[:, X4]
        new_label3 = X[:, X2] / X[:, X1]
        return np.c_[X, new_label1, new_label2, new_label3]


# show input data
# attr_adder = CombineAttributesAdder()
# housing_extra_attribs = attr_adder.transform(data.values)
# print(housing_extra_attribs)

