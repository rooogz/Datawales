
##顺序栈
class Arrstack:
	def __init__(self):
		self.stack = []
	def __str__(self):
		return self.stack.__str__()
	def pop(self):
		return self.stack.pop()
	def push(self, elem):
		self.stack.append(elem)
	@property
	def size(self):
		return len(self.stack)
	@property
	def is_empty(self):
		return len(self.stack) == 0
	def display(self):
		print(self.stack)

##恋栈节点
class Node:
	def __init__(self, value = None, next = None):
		self.value = value
		self.next = None
	##使得节点可以直接打印
	def __str__(self):
		return str(self.value)
##恋栈
class Linkstack:
	_top = None
	def __init__(self):
		pass
	##这个方法作为类属性一样使用，不用加括号
	@property
	def is_empty(self):
		return self._top is None

	def push(self, value):
		node = self._top
		self._top = Node(value)
		self._top.next = node
		return True

	def pop(self):
		if self.is_empty:
			return None
		node = self._top
		self._top = node.next
		return node 
	##生成器，生成整个栈的迭代器
	def _traversal(self):
		node = self._top
		##注如果栈为空生成空迭代器
		while node :
			yield node 
			node = node.next
	def display(self):
		print('\n'.join(map(lambda node: '|{:^7}|'.format(str(node) ), self._traversal() ) ) + '\n' + 7 * '-' )



if __name__ == '__main__':
	# stack_test = Linkstack()
	# # for i in range(10):
	# # 	stack_test.push(i)
	# print(stack_test._traversal())
	# it = stack_test._traversal()
	# next(it)
	# stack_test.display()
	stack_t =	Arrstack()
	for i in range(10):
		stack_t.push(i)
	print(stack_t)
	print(stack_t.size)
	print(stack_t.is_empty)
	for i in range(10):
		x = stack_t.pop()
		print(stack_t)
		#print('pop %d'%x )
	print(stack_t.size)
	print(stack_t.is_empty)