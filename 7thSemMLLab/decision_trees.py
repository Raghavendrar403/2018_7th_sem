import csv
import math

global_concept = []
outputFile = open("otp","w")

def just_remove_the_row(concept, attr_index):
	new_concept
	

def reorder(concept, attr, index):
	print("ATTR = ",attr,"\n")
	indices = []	
	concept_T = list(map(list, zip(*concept))) # traspose of concept
	concept_T = concept_T[:-1] # remove the last PlaySport row
	concept = list(map(list,zip(*concept_T))) 
	for i, row in enumerate(concept):
		if(row[index] == attr):
			indices.append(i)	
	return indices

def calc_entropy(pos,neg):
	prob = pos+neg
	if(pos == 0 or neg == 0):
		return 0

	entropy = (pos/prob)*math.log2(pos/prob) + (neg/prob)*math.log2(neg/prob)
	return -entropy

def cal_info_gain(current_entropy, total_prob, all_entropy, indi_prob):
	info_gain = 0
	for entropy, attr in zip(all_entropy, indi_prob):
		info_gain += (attr/total_prob)*entropy	

	return (current_entropy - info_gain)

def entropy_call(concept, entropy, headers, n):
	# base case for the recursive function	
	#print("N: ",n,"  ",headers)
	##print("="*100)
	#for sample in concept:
	#	#print(sample)
	if(entropy == 0):
		return 
	
#################### find all the unique attr ###############################
	concept_T =	list(map(list,zip(*concept))) # get the Transpose of concept
	unique_attr = [[] for i in range(len(concept_T))] # a list of unique attributes for each row
	attr_list = [{} for i in range(len(concept_T))] # a dictionary of Yes and No for each unique attribute in each row
	entropy_list = [{} for i in range(len(concept_T))] # a dictionary for entropies of each uniques attribute of each row
	info_gain = [0 for i in range(len(concept_T))]

	# i will be the index to the row
	for i, row in enumerate(concept_T[:-1]):
		# find the attributes from the row which are not present in the unique_attr[i]
		for attr in row:
			if(attr not in unique_attr[i]):
				unique_attr[i].append(attr)
		# #print(headers[i],":",unique_attr[i])

		# calculate the entropies of each attribute individually for 
		# first add each attribute to the attr_list dict with yes and no
		for j, attr in enumerate(row):
			if(attr not in attr_list[i].keys()):
				attr_list[i][attr] = []

			attr_list[i][attr].append(concept_T[-1][j])
		##print(attr_list[i])
		# calculate the entropy of each unique attribute in the row
		for attr in unique_attr[i]:
		  entropy_list[i][attr] = calc_entropy(attr_list[i][attr].count("Yes"), attr_list[i][attr].count("No"))
		##print(entropy_list[i])

		# calculate the information gain for that row

		# first find the count of each attribute in a row
		attr_count = [len(attr_list[i][x]) for x in attr_list[i].keys()]
		list_entropy = [entropy_list[i][attr] for attr in entropy_list[i].keys()]
		##print(list_entropy)
		##print(attr_count)
		info_gain[i] = cal_info_gain(entropy, sum(attr_count), list_entropy, attr_count)
		#print(headers[i],":",info_gain[i])

	# choose the split attribute	
	# find the attribute of the maximum info gain
	max_info_gain = max(info_gain)
	attr_index = info_gain.index(max_info_gain)
	split_attribute = headers[attr_index]


	print("SPLIT ATTRIBUTE: ", split_attribute, " : ", max_info_gain)
	#print("HEADERS: ",headers,"\n")
	#for sample in concept:
	#	print(sample)
	#print("\n")
	
	#print("ENTROPY LIST: ", entropy_list[attr_index])
	

	outputFile.write("SPLIT_ATTRIBUTE AT "+str(n)+" is "+split_attribute+"\n")

	# build the concept without Outlook in it
	# Re-order the concept according to the attributes of Outlook
	new_concept = {}
	for attr in unique_attr[attr_index]:
		if(entropy_list[attr_index][attr] != 0):
			reorder_indexes = reorder(concept, attr, attr_index)
			##print(reorder_indexes)
			new_concept[attr] = []
			for i in reorder_indexes:
				try :
					row = [attr for attr in concept[i]]
				except:
					print(row,"\n")
					#print(i,"\n")
					#print(concept[i])

				row.remove(row[attr_index])
				new_concept[attr].append(row)
		else:
			
			outputFile.write(attr+":"+str(attr_list[attr_index][attr][0]+"\n"))
	if(new_concept != {}):
		headers.remove(split_attribute)	
	for attr in new_concept.keys():
		entropy_of_attr = entropy_list[attr_index][attr]
		if(entropy_of_attr != 0):
			#print("ATTR: ",attr)
			outputFile.write(attr+"--->")
			entropy_call(new_concept[attr], entropy_of_attr, headers,n+1)
								

with open("dataset.csv") as csvData:
	dataFile = list(csv.reader(csvData))

	headers = dataFile[0]
	dataFile = dataFile[1:]
	for sample in dataFile:
		global_concept.append(sample)	

	entropy_call(dataFile, 0.9402, headers,1)

	outputFile.close()
