

class Arrstack:
	def __init__(self):
		self.stack = []
	def pop(self):
		return self.stack.pop()
	def push(self, elem):
		self.stack.append(elem)
	def size(self):
		return len(self.stack)
	def is_empty(self):
		return len(self.stak) == 0


class LinkNode:
	def __init__(self, value):
		self.value = value
		self.next = None

class Linkstack：
