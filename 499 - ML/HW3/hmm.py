import numpy as np
import math

# KORAY CAN YURTSEVEN
# 2099547

# Given transition probability matrix and observation estimates for every state
# Return the probability of the given observations to occur
def forward(trans, estimate, obs):
	forward_matrix = []
	
	# Initialize
	temp_row = []
	for i in range(len(trans)):
		temp_row.append(trans[0][i] * estimate[i][obs[0]])
	forward_matrix.append(temp_row)
	
	#print(forward_matrix) 
	
	# we need to go len(obs) step
	# I have started this loop from 1
	# because I have used 0th index element in the initialization part
	for t in range(1, len(obs)):

		forward_matrix_row2 = []
		#print("lenobs:" , len(obs))
		
		# we have our forward matrix
		# iterate inside this matrix
		# I have started this loop from 1
		# because I have already calculated the first row in initialization part
		for i in range(1, len(forward_matrix[0])):
			
			# sum_array stores the computation from one node to all other nodes
			# in the next level
			sum_array = []
			for j in range(len(trans)):
			
				#print("forward_matrix[-1][i]: " + str(forward_matrix[-1][i]))
				#print("trans[i][j]: " + str(trans[i][j]))
				#print("estimate[j][obs[t]]: " + str(estimate[j][obs[t]]))
				sum_array.append(forward_matrix[-1][i] * trans[i][j] * estimate[j][obs[t]])
			
			# row2 stores from all nodes in one level to all others in the next level
			forward_matrix_row2.append(sum_array)
	
		# now we have all the information from first layer to the second layer
		# to find next levels probabilities
		# we need to sum those layers like in the below
		
		tmp2 =[]
		for j in range(len(forward_matrix_row2[0])):
			temp = 0
			for i in range(len(forward_matrix_row2)):
				temp += forward_matrix_row2[i][j]
			#print(j, i,temp)
			tmp2.append(temp)
		#print(tmp2)
		forward_matrix.append(tmp2)
		#print(forward_matrix)
		
		# now repeat till we don't have any observed data		
			
	# to find probabilities, we need to go from last nodes to end nodes
	result = 0
	for i in range(len(forward_matrix[-1])):
		result += forward_matrix[-1][i] * trans[i][-1]
	#print("forward result: " ,result)
	return result
	
	

# Given the transition probability matrix and observation estimates for every state
# Return the hidden states that the given observations cause HMM to visit with highest probability
# Hidden states should be returned as indexes as their names will not be supplied
# Do not include start and end states
def viterbi(trans, estimate, obs):

	V = []
	
	# find path
	backtrack = []
	for i in range(len(trans)):
		backtrack.append([0])
		
	# initialize
	temp_row = []
		
	for i in range(len(trans)):
		temp_row.append(trans[0][i] * estimate[i][obs[0]])
	V.append(temp_row)
	
	for t in range(1, len(obs)):
		row2 = []

		for i in range(len(trans)):
			# Vpath holds, from 1 node in current level to all nodes in the next level
			Vpath = []
			
			for j in range(len(trans)):
				# calculate from 1 node in the current level,
				# to next 1 node in the next level
				# append them together to find maximum of them
				Vpath.append(V[-1][i] * trans[i][j] * estimate[j][obs[t]])

			row2.append(Vpath)
		
		# in tmp2 array, store the highest elements
		tmp2 = []

		for j in range(len(row2[0])):
			tmp_element = 0
			for i in range(len(row2)):
				# find the highest element
				if (row2[i][j] > tmp_element):
					tmp_element = row2[i][j]
			tmp2.append(tmp_element)

		for j in range(len(trans)):
			tmpIndex = -1
			tmpVal = -1
			for i in range(len(trans)):
				if(V[-1][i] * trans[i][j] > tmpVal):
					tmpVal = V[-1][i] * trans[i][j]
					tmpIndex  = i
			backtrack[j].append(tmpIndex)
		V.append(tmp2)	
	
	
	
	returnList = []
	
	lastIndex = -1
	lastVal = -1
	for i in range(len(trans)):
		if(V[-1][i] * trans[i][-1] > lastVal):
			lastVal = V[-1][i] * trans[i][-1]
			lastIndex = i
	
	#print(backtrack)
	#print(lastIndex)
	
	t = len(obs)
	for i in range(len(obs)):
		returnList = [lastIndex] + returnList
		#returnList.append(lastIndex)
		t = t -1
		lastIndex = backtrack[lastIndex][t]
		
	
	#print(returnList)
	#print(V)
	return returnList

# Example transition matrixes from the notes. First column and row is the start state, last column and row are end state.
# trans[row][col] indicates transition from state represented with a row to a state represented with a column.
'''
state_name_example = ['start', 'hot', 'cold', 'end']
trans_matrix_example = [
			[0.0, 0.8, 0.2, 0.0],
			[0.0, 0.6, 0.3, 0.1],
			[0.0, 0.4, 0.5, 0.1],
			[0.0, 0.0, 0.0, 0.0]
]
observation_types_examples = [1, 2, 3]
# Estimates include start and end states as well but they are guaranteed to be zero.
observation_estimates = [
			[0.0, 0.0, 0.0],
			[0.2, 0.4, 0.4],
			[0.5, 0.4, 0.1],
			[0.0, 0.0, 0.0]
]

if forward(trans_matrix_example, observation_estimates, [2, 0, 2]) == 0.002193:
	print("Forward example is correct")

if viterbi(trans_matrix_example, observation_estimates, [2, 0, 2]) == [1, 1, 1]:
	print("Viterbi example is correct")

#print(forward(trans_matrix_example, observation_estimates, [0, 0, 0, 0]))
#print(viterbi(trans_matrix_example, observation_estimates, [0, 0, 0, 0]))

trans2=[[0.0, 0.0743, 0.1352, 0.1534, 0.1456, 0.1688, 0.3227, 0.0],
 [0.0, 0.056, 0.2833, 0.2007, 0.064, 0.075, 0.2515, 0.0695],
 [0.0, 0.1071, 0.128, 0.2121, 0.1496, 0.117, 0.2009, 0.0853],
 [0.0, 0.0248, 0.2431, 0.1859, 0.2164, 0.1004, 0.1761, 0.0533],
 [0.0, 0.3176, 0.189, 0.0691, 0.1065, 0.2229, 0.0109, 0.084],
 [0.0, 0.1009, 0.0659, 0.0734, 0.0417, 0.263, 0.2514, 0.2037],
 [0.0, 0.2202, 0.0034, 0.0301, 0.3312, 0.0992, 0.1029, 0.213],
 [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]]
estimate2=[[0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0],
 [0.1504, 0.0983, 0.0668, 0.1586, 0.1886, 0.0796, 0.0932, 0.1644],
 [0.0462, 0.1213, 0.1256, 0.2104, 0.2302, 0.0047, 0.0559, 0.2058],
 [0.1522, 0.048, 0.1708, 0.1389, 0.0738, 0.0565, 0.2167, 0.143],
 [0.0836, 0.0424, 0.0068, 0.2924, 0.0458, 0.2093, 0.2829, 0.0368],
 [0.2812, 0.0403, 0.1687, 0.0271, 0.1419, 0.1155, 0.1147, 0.1107],
 [0.0912, 0.0656, 0.1448, 0.2317, 0.1722, 0.0102, 0.2503, 0.0342],
 [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]]
forward_examples2=[(trans2,
  estimate2,
  [7, 2, 2, 3, 1, 4, 7, 6, 4, 4, 0, 5, 6],
  3.6031424833948744e-14),
 (trans2, estimate2, [3, 7, 3, 3, 1, 4, 1, 3, 3, 1], 3.973654261085672e-11),
 (trans2,
  estimate2,
  [3, 4, 5, 5, 5, 6, 1, 7, 1, 1, 2, 4],
  2.8657568870634703e-14),
 (trans2, estimate2, [7, 5, 2, 6, 3], 1.7225445983339082e-06),
 (trans2, estimate2, [5, 5, 6, 5, 2, 2], 7.256111463165952e-08),
 (trans2, estimate2, [5, 2, 2, 5, 1, 2, 5, 3, 5], 2.833638172201552e-11),
 (trans2, estimate2, [7, 2, 6, 3, 4, 4, 7, 7, 6], 7.789495504638606e-10),
 (trans2, estimate2, [7, 3, 2, 5, 3, 4], 2.2411037430248192e-07),
 (trans2, estimate2, [2, 4, 3, 3, 1, 3, 2, 0], 5.4817868801664206e-09),
 (trans2,
  estimate2,
  [3, 4, 5, 2, 1, 0, 4, 4, 7, 7, 2],
  1.9838968633846837e-12)]
viterbi_examples2=[(trans2,
  estimate2,
  [0, 4, 7, 6, 0, 6, 0, 7, 0, 1, 7, 3, 5, 3],
  [6, 1, 2, 4, 5, 6, 1, 2, 3, 2, 3, 4, 5, 6]),
 (trans2, estimate2, [6, 7, 6], [6, 1, 6]),
 (trans2, estimate2, [0, 0], [5, 5]),
 (trans2,
  estimate2,
  [0, 0, 7, 6, 0, 1, 6, 1, 2],
  [5, 5, 5, 5, 5, 6, 4, 1, 6]),
 (trans2,
  estimate2,
  [1, 6, 3, 0, 2, 7, 6, 0, 4, 3, 6, 4, 5, 0],
  [2, 6, 4, 1, 3, 2, 4, 5, 6, 4, 1, 6, 4, 5]),
 (trans2,
  estimate2,
  [2, 6, 6, 6, 4, 2, 6, 0, 6, 7, 5, 7, 3, 4],
  [6, 1, 6, 4, 1, 6, 4, 1, 3, 2, 4, 1, 2, 6]),
 (trans2, estimate2, [5, 1, 4, 0, 1, 5, 5], [4, 1, 2, 5, 6, 4, 5]),
 (trans2,
  estimate2,
  [7, 7, 4, 3, 3, 0, 2, 0, 6, 7, 4, 5, 3, 0],
  [2, 3, 2, 6, 4, 5, 5, 5, 6, 1, 6, 4, 4, 5]),
 (trans2, estimate2, [4, 3, 3, 5, 2, 1, 4, 6], [6, 1, 6, 4, 5, 6, 1, 6]),
 (trans2, estimate2, [1, 3, 0, 7], [6, 4, 5, 5])]
 
 
 
for i in range(len(forward_examples2)):
 	if(forward(trans2, estimate2, forward_examples2[i][2]) == forward_examples2[i][3]):
 		print("forward correct")
 	else:
 		print("forward FALSE")
for i in range(len(viterbi_examples2)):
 	if(viterbi(trans2, estimate2, viterbi_examples2[i][2]) == viterbi_examples2[i][3]):
 		print("viterbi correct")
	else:
 		print("viterbi FALSE")
'''
# Feel free to try many more examples like these to check your implementation


