import math

def sigmoid(x):
	if x == 0:
		return 0
	
	else:
		return 1/(1+math.e**(-x))


class NeuralNet:
	def __init__(self, x, y):
		self.input = x
		self.weights1 = math.random(
		
