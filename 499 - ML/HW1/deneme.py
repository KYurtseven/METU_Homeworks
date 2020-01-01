import tensorflow as tf
'''
a = tf.constant(3.0)
b = tf.constant(4.0)
total = a + b
print(a)
print(b)
print(total)

ses = tf.Session()
print("total: " + str(ses.run(total)))

vec = tf.random_uniform(shape=(3,2))
out1 = vec + 1
out2 = vec + 2
print('vec')
print(ses.run(vec))
print('out1')
print(ses.run(out1))

print('vec')
print(ses.run(vec))

x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)

z = x + y
print('z')
print(ses.run(z, feed_dict={x: 3, y: 4.5}))
print('x + y')
print(ses.run(z, feed_dict={x: [1,2], y: 4.5}))
print('x + y')
print(ses.run(z, feed_dict={x: [1,2], y: [2,3]}))

my_data = [[0,1], [2,3], [4,5], [6,7]]


slices = tf.data.Dataset.from_tensor_slices(my_data)
#making iterator
next_item = slices.make_one_shot_iterator().get_next()
print('iterator')
while(True):
	try:
		print(ses.run(next_item))
	except tf.errors.OutOfRangeError:
		break
		
# What is it?
layer_x = tf.placeholder(tf.float32, shape=[None, 3])
linear_model = tf.layers.Dense(units=1)
layer_y= linear_model(layer_x)


# not recommended
# layer_y = tf.layers.dense(layer_x, units=1)
# why?


# add this before graph
# note that, this initailizes variables that existed in the graph 
# initializer should be one of the last things added during graph construction
init = tf.global_variables_initializer()

ses.run(init)
print("after init, creating layers:")
print(ses.run(layer_y, {layer_x: [[1,2,3], [4,5,6],[7,8,9]]}))

'''

# define data
# input data
x = tf.constant([[1], [2], [3], [4]], dtype = tf.float32)
# expected output
y_true = tf.constant([[0], [-1], [-2], [-3]], dtype = tf.float32)

linear_model = tf.layers.Dense(units=1)
y_pred = linear_model(x)

sess = tf.Session()
init = tf.global_variables_initializer()
sess.run(init)
print("first run")
print(sess.run(y_pred))

loss = tf.losses.mean_squared_error(labels= y_true, predictions= y_pred)

print("loss")
print(sess.run(loss))

optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)

for i in range(100):
	_, loss_value = sess.run((train, loss))
	#print(loss_value)

print("final y")
print(sess.run(y_pred))
