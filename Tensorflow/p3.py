import tensorflow as tf

x = tf.Variable(0, name='x')

model = tf.global_variables_initializer()

with tf.Session() as session:
	session.run(model)
	for i in range(5):
		x = x+i
		print(session.run(x))
