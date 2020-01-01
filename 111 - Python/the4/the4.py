def isleaf(tree):
	return len(tree) == 1
def datum(tree):
	return tree[0]
def children(tree):
	return tree[1:]
def cp(tree):
	return datum(tree)[1]
def wp(tree):
	return datum(tree)[2]

def getKey(item):
    return item[4]

def sumtree(tree):
	if isleaf(tree):
		return wp(tree)-cp(tree)
	else:
		total = wp(tree)-cp(tree)
		for child in children(tree):
			total += sumtree(child)
		return total

glo = []

def traverse(tree, i):
	global glo
	glo.append(datum(tree) + [i])
	if not isleaf(tree):
		for child in children(tree):
			traverse(child, i+1)

def cut(node):
	if node[3] > 1 and node[2] > node[1]:
		if node[2] > node[3] * 100:
			return node[3] * 100
		else:
			return node[2] - 1
	else:
		return 0

def help_michael(mafia_tree, savings):
	global glo
	glo = []
	traverse(mafia_tree, 0)

	need = sumtree(mafia_tree) - savings

	if need <= 0 :
		return "Yes"

	glo2 = []
	for i in glo:
		glo2.append(i + [cut(i)])
	glo2=sorted(glo2, key=getKey, reverse=True)

	ret = ['Possible']

	for i in glo2:
		if need > 0:
			if i[4] > 0:
				if i[4] >= need:
					ret.append([i[0], i[2] - need])
					break
				else:
					ret.append([i[0], i[2] - i[4]])
					need -= i[4]

			else:
				return "No"

	return ret


