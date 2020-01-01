import tensorflow as tf
import pickle
import matplotlib.pyplot as plt

bank = pickle.load(open('bank.pkl', 'rb', 2))

x_train = bank['x_train']
y_train = bank['y_train']

x_test = bank['x_test']
y_test = bank['y_test']


x = tf.placeholder(tf.float32, shape = [None,4])
y = tf.placeholder(tf.float32, shape = [None,2])

first_layer = tf.layers.dense(x, 8, activation = tf.nn.sigmoid)
second_layer = tf.layers.dense(first_layer, 4, activation = tf.nn.sigmoid)
third_layer = tf.layers.dense(second_layer, 3, activation = tf.nn.sigmoid)
output = tf.layers.dense(third_layer, 2)

loss = tf.losses.softmax_cross_entropy(onehot_labels= y, logits = output)

optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)

accuracy = tf.metrics.accuracy(tf.argmax(y,1), tf.argmax(output,1))

# Inits
init_g = tf.global_variables_initializer()
init_l = tf.local_variables_initializer()

with tf.Session() as sess:

	sess.run(init_g)
	sess.run(init_l)
	# end of inits
	for i in range(8000):
		sess.run(train, feed_dict={x: x_train, y: y_train})
		
		c = sess.run(loss, feed_dict={x: x_train, y:y_train})
		print("Epoch: " + str(i) + " loss: " + str(c))
		plt.plot(i, c, 'bo', label='Testing data')
	
	
	#print("Optimization finished")
	training_cost = sess.run(loss, feed_dict={x: x_train, y: y_train})
	#print("training cost: " + str(training_cost))
	
	
	#print("Testing")
	
	#testing_cost = sess.run(loss, feed_dict={x: x_test, y: y_test})
	#print("Test cost: " + str(testing_cost))
	
	print("Accuracy: " +  str(sess.run(accuracy, feed_dict={x: x_test, y: y_test})))
	
	plt.show()
