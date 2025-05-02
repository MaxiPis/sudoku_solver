# https://scikit-learn.org/stable/modules/generated/sklearn.datasets.load_digits.html
# https://scikit-learn.org/stable/auto_examples/classification/plot_digits_classification.html#sphx-glr-auto-examples-classification-plot-digits-classification-py
from sklearn.neural_network import MLPClassifier
from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import matplotlib
import numpy as np
import PIL
import urllib

digits = load_digits()
X = digits.data      # 8x8 images flattened to 64 features
y = digits.target    # Labels: 0 to 9

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

clf = MLPClassifier(hidden_layer_sizes=(100,), activation='relu', solver='adam', max_iter=300)
clf.fit(X_train, y_train)

url = "/img/num_test.png"
fname = np.array(PIL.Image.open(urllib.request.urlopen(url)))
matplotlib.pyplot.imread(fname, format=None)
sample = X_test[0].reshape(1, -1)
print("Predicted:", clf.predict(sample))
print("Actual:   ", y_test[0])

