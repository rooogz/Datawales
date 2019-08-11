#顺序循环队列
#少用一个位置，用head在rear的顺时针数下一个位置来判断队列已满
class Queue:
	__capa = 10 #存储空间总大小，实际少用1个空间
	def __init__(self, capabilty = 10):
		self.zone = [None]*capabilty
		self.h = 0
		self.r = 0
		self.__capa = capabilty
	@property
	def is_empty(self):
		return self.h == self.r
	@property
	def is_full(self):
		return ((self.r + 1) % self.__capa ) == self.h

	def append(self, elem):
		if self.is_full:
			print('队列满，结束插入')
			return False
		self.zone[self.r] = elem
		self.r = (self.r + 1) % self.__capa
		return True

	def appendArry(self, Arr):
		if not Arr:
			return False
		for elem in Arr :
			self.append(elem)
		return True

	def remove(self, n):
		count = n
		while (not self.is_empty) and (count!=0) :
			arr =[]
			elem = self.zone[self.h]
			self.h = (self.h + 1) % self.__capa
			arr.append(elem)
			count -= 1
		if count > 0:
			print("队列已空，仅能移出%d个元素！"%(n - count))

	def display(self):
		if self.r >= self.h :
			print(self.zone[self.h : self.r])
		else:
			l1 = self.zone[self.h : ]
			# print('l1')
			# print(l1)
			l2 =self.zone[0 : self.r]
			# print('l2')
			# print(l2)
			l1.extend(l2)
			print(l1)




if __name__ == '__main__':
	q_t = Queue()
	q_t.display()
	print("add[0 2 4 5 2 7 6]")
	q_t.appendArry([0,2,4,5,2,7,6])
	q_t.display()
	print("remove 9")
	q_t.remove(9)
	q_t.display()
	print("add[3,77,5,4,2,46]")
	q_t.appendArry([3,77,5,4,2,46])
	q_t.display()
	print("add[100,666]")
	q_t.appendArry([100,666])
	q_t.display()
	print("remove 5")
	q_t.remove(5)
	q_t.display()




