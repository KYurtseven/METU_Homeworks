import tensorflow as tf
import pickle
import matplotlib.pyplot as plt

magic = pickle.load(open('magic.pkl', 'rb', 2))

x_train = magic['x_train']
y_train = magic['y_train']

x_test = magic['x_test']
y_test = magic['y_test']


x = tf.placeholder(tf.float32, shape = [None,10])
y = tf.placeholder(tf.float32, shape = [None,2])

first_layer = tf.layers.dense(x, 8, activation = tf.nn.relu)
second_layer = tf.layers.dense(first_layer, 4, activation = tf.nn.relu)
third_layer = tf.layers.dense(second_layer, 3, activation = tf.nn.relu)
output = tf.layers.dense(third_layer, 2, activation = tf.nn.softmax)

loss = tf.losses.softmax_cross_entropy(onehot_labels= y, logits = output)



with tf.Session() as sess:
	learning_rate = 0.07
	
	
	optimizer = tf.train.GradientDescentOptimizer(learning_rate)
	train = optimizer.minimize(loss)

	accuracy = tf.metrics.accuracy(tf.argmax(y,1), tf.argmax(output,1))

	# Inits
	init_g = tf.global_variables_initializer()
	init_l = tf.local_variables_initializer()

	sess.run(init_g)
	sess.run(init_l)
	# end of inits
	for i in range(8000):
		sess.run(train, feed_dict={x: x_train, y: y_train})
	
		c = sess.run(loss, feed_dict={x: x_train, y:y_train})
		
		plt.plot(i, c, 'bo', label='Testing data')
		
	print("Epoch: " + str(i) + " loss: " + str(c))
	print("Accuracy: " +  str(sess.run(accuracy, feed_dict={x: x_test, y: y_test})))
	

	plt.show()

#ttr rate 0.1, loss 0.5402, acc 0.76297
#rrr rate 0.07, loss 0.4947, acc 0.818
#rrr rate 0.1, loss 0.495, acc 0.819 ,20-10-5


