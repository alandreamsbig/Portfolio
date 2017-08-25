#!user/bin/python
#Alan Tsai
#CS260
#List Concatenate

class concatenate: 
	def __init__(self):
		self.list = [ 'This', 'is', 'a', 'list' ]; #created a list
		newlist = [ 'NewWords', 'another', 'list', 'testing123']; #create another list

		print(str(self.list) + "\n");
		print("Adding a new list "); print(newlist); print("to the list \n");
		print("Final concatenate list");
		print(self.concatenate(self.list, newlist)); #concatenate the lists
		print("\n");

	def concatenate(self, array, concatenate_this):
		return array + [concatenate_this];

if (__name__ == "__main__"):
	root = concatenate();
