import sys
import linecache
'''
with open(sys.argv[1], 'r') as my_file:
	x = lines[0].strip()
	x = x.replace("[", "\[")
	x = x.replace("]", "\]")
	x = x.replace('"', '\\"')
	x = x.replace(' ', '')
	x = x.replace("	", '')
	print x
'''
# Read in the file
with open('organized.txt', 'r') as file :
  filedata = file.read()

# Replace the target string
filedata = filedata.replace("'", '"')

# Write the file out again
with open('organized.txt', 'w') as file:
  file.write(filedata)


