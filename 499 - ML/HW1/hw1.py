import tensorflow as tf
import pickle
import numpy as np
import matplotlib.pyplot as plt

def convertToTensor(arg):
	arg_np = np.asarray(arg, np.float32)
	arg2 = tf.convert_to_tensor(arg_np, np.float32)
	return arg2

bank = pickle.load(open('bank.pkl', 'rb', 2))

x_train = bank['x_train']
y_train = bank['y_train']

x_test = bank['x_test']
y_test = bank['y_test']

'''
# convert python arrays to tensor
x_train_tensor = convertToTensor(x_train)
y_train_tensor = convertToTensor(y_train)

#print(x_train)

sess = tf.Session()

first_layer = tf.layers.dense(x_train_tensor, 3, activation = tf.nn.sigmoid)
output = tf.layers.dense(first_layer, 2, activation = tf.nn.softmax)
#prediction = tf.layers.dense(first_layer, 2, activation = tf.nn.softmax)

#loss = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits_v2(prediction, y_train))
loss = tf.losses.softmax_cross_entropy(onehot_labels= y_train, logits = output)
#correct_prediction = tf.equal(tf.argmax(y_train,1), tf.argmax(output,1))
accuracy = tf.metrics.accuracy(tf.argmax(y_train,1), tf.argmax(output,1))

init_g = tf.global_variables_initializer()
init_l = tf.local_variables_initializer()
optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)

sess.run(init_g)
sess.run(init_l)
#print(sess.run(train, feed_dict={x_train_tensor: x_train, y_true: y_train}))

for i in range(2000):
	_, loss_value = sess.run((train, loss))
	#sess.run(train, feed_dict={x_train_tensor: x_train_tensor ,output: y_test})
	#_, loss_value = sess.run([optimizer, loss], feed_dict={x: x_train, y: y_train})
	print("Epoch: " + str(i) + " " + "Loss: " + str(loss_value))
	#if i%50 == 0:
		#print("i: " + str(i) + " loss_value: " + str(loss_value))
print("Test Accuracy: " + str(sess.run(accuracy)))

'''
x = tf.placeholder(tf.float32, shape = [None,4])
y = tf.placeholder(tf.float32, shape = [None,2])

first_layer = tf.layers.dense(x, 3, activation = tf.nn.sigmoid)
output = tf.layers.dense(first_layer, 2)

loss = tf.losses.softmax_cross_entropy(onehot_labels= y, logits = output)

optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)

#correct_prediction = tf.equal(tf.argmax(y_train, 1), tf.argmax(output, 1))
#accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
accuracy = tf.metrics.accuracy(tf.argmax(y,1), tf.argmax(output,1))

# Inits
init_g = tf.global_variables_initializer()
init_l = tf.local_variables_initializer()

with tf.Session() as sess:

	sess.run(init_g)
	sess.run(init_l)
	# end of inits
	for i in range(2000):
		sess.run(train, feed_dict={x: x_train, y: y_train})
		
		c = sess.run(loss, feed_dict={x: x_train, y:y_train})
		print("Epoch: " + str(i) + " loss: " + str(c))
		plt.plot(i, c, 'bo', label='Testing data')
	
	
	print("Optimization finished")
	training_cost = sess.run(loss, feed_dict={x: x_train, y: y_train})
	print("training cost: " + str(training_cost))
	
	
	print("Testing")
	
	testing_cost = sess.run(loss, feed_dict={x: x_test, y: y_test})
	print("Test cost: " + str(testing_cost))
	
	print("Accuracy: " +  str(sess.run(accuracy, feed_dict={x: x_test, y: y_test})))
	
	plt.show()
	
	#plt.plot(x_test, y_test, 'bo', label='Testing data')
	#plt.show()
'''
print(sess.run(output))
summary = tf.summary.merge_all()
writer = tf.summary.FileWrite('logs', sess.graph)

print("Accuracy" + str(sess.run(accuracy.eval({X: X_test, Y:y_test}))))
result = sess.run(x_pred, feed_dict = {x: x_test})

print(sess.run(accuracy, feed_dict={x: x_test, y: y_test}))

#with tf.Session() as sess:
writer = tf.summary.FileWriter('logs', sess.graph)
print(sess.run(accuracy))
writer.close()
#print("j: " + str(j) + " " + str(sess.run(accuracy)))
#j += 0.01 
'''
