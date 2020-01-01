def gcd(item1, item2):
    r = item1 % item2
    if r == 0:
        return item2

    return gcd(item2, r)    


def matrix_mul(A):
   
	if len(A)==1:
		return A[0]

	mat1 = mateval(A[0])
	mat2 = mateval(A[1])

	if isMatrix(mat1) and isMatrix(mat2):
		result = []
	        num_rowsA = len(mat1) # number of rows of A
	        num_colsA = len(mat1[0]) # number of cols of A
	        num_colsB = len(mat2[0]) # number of cols of B
	        for i in range(num_rowsA):
		    result.append([])
		    for j in range(num_colsB):
		        result[i].append(0)
		        for k in range(num_colsA):
			    result[i][j] = matrix_add([matrix_mul([mat1[i][k], mat2[k][j]]), result[i][j]])
	        return matrix_mul([result] + A[2:])
	elif not isMatrix(mat1) and isMatrix(mat2):
		ret = []
		raw = len(mat2)
		col = len(mat2[0])
		
		for i in range(raw):
			tmp = []
			for j in range(col):
				tmp.append(matrix_mul([mat1, mat2[i][j]]))
			ret.append(tmp)
		return matrix_mul([ret] + A[2:])
	elif isMatrix(mat1) and not isMatrix(mat2):
		ret = []
		raw = len(mat1)
		col = len(mat1[0])
		
		for i in range(raw):
			tmp = []
			for j in range(col):
				tmp.append(matrix_mul([mat1[i][j], mat2]))
			ret.append(tmp)
		return matrix_mul([ret] + A[2:])
		
	
	elif type(mat1) != list and type(mat2) != list:
		return matrix_mul([mat1*mat2] + A[2:])
	elif type(mat1) != list and type(mat2) == list:
		return matrix_mul([make_rat(mat1*mat2[0], mat2[1])] + A[2:])
	elif type(mat1) == list and type(mat2) != list:
		return matrix_mul([make_rat(mat1[0]*mat2, mat1[1])] + A[2:])
	else:
		return matrix_mul([make_rat(mat1[0]*mat2[0], mat1[1]*mat2[1])] + A[2:])

def matrix_add(A):

	if len(A)==1:
		return A[0]

	mat1 = mateval(A[0])
	mat2 = mateval(A[1])

	if isMatrix(mat1):
		ret = []
		raw = len(mat1)
		col = len(mat1[0])
		
		for i in range(raw):
			tmp = []
			for j in range(col):
				tmp.append(matrix_add([mat1[i][j], mat2[i][j]]))
			ret.append(tmp)
		return matrix_add([ret] + A[2:])
	
	elif type(mat1) != list and type(mat2) != list:
		return matrix_add([mat1+mat2] + A[2:])
	elif type(mat1) != list and type(mat2) == list:
		return matrix_add([make_rat(mat1*mat2[1]+mat2[0], mat2[1])] + A[2:])
	elif type(mat1) == list and type(mat2) != list:
		return matrix_add([make_rat(mat1[0]+mat2*mat1[1], mat1[1])] + A[2:])
	else:
		return matrix_add([make_rat(mat1[0]*mat2[1]+mat2[0]*mat1[1], mat1[1]*mat2[1])] + A[2:])

def matrix_sub(A):
	
	mat1 = mateval(A[0])
	mat2 = mateval(A[1])

	if isMatrix(mat1):
		ret = []
		raw = len(mat1)
		col = len(mat1[0])
		
		for i in range(raw):
			tmp = []
			for j in range(col):
				tmp.append(matrix_sub([mat1[i][j], mat2[i][j]]))
			ret.append(tmp)
		return ret
	
	elif type(mat1) != list and type(mat2) != list:
		return mat1-mat2
	elif type(mat1) != list and type(mat2) == list:
		return make_rat(mat1*mat2[1]-mat2[0], mat2[1])
	elif type(mat1) == list and type(mat2) != list:
		return make_rat(mat1[0]-mat2*mat1[1], mat1[1])
	else:
		return make_rat(mat1[0]*mat2[1]-mat2[0]*mat1[1], mat1[1]*mat2[1])

def isMatrix(x):
	if type(x)==list:
		for i in x:
			if type(i)!=list:
				return False
		return True
	return False
 


def make_rat(nomin, denom):
    gcd_rat = gcd(nomin, denom)
    if denom/gcd_rat == 1:
	return nomin/gcd_rat
    return [nomin/gcd_rat, denom/gcd_rat]


def mateval(lst):
	
	if type(lst) !=list :
		return lst
		
	if lst[0] == '+':
		return matrix_add(lst[1:])
	elif lst[0] == '*':
		return matrix_mul(lst[1:])
	elif lst[0] == '-':
		return matrix_sub(lst[1:])
	else:
		return lst
		
		
