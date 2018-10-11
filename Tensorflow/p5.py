import tensorflow as tf
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import os

dir_path = os.path.dirname(os.path.realpath(__file__))

filename = dir_path + "/1.jpg"

image = mpimg.imread(filename)
height, width, depth = image.shape

x = tf.Variable(image, name='x')
model = tf.global_variables_initializer()

with tf.Session() as session:
	x = tf.reverse_sequence(x, [width] * height, seq_dim=1)
	session.run(model)
	result = session.run(x)
	plt.imshow(result)
	plt.show()
	x = tf.transpose(x, perm=[1,0,2])
	result = session.run(x)
	plt.imshow(result)
	plt.show()
