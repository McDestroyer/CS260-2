
class TreeNode:
	def __init__(self, value):
		self.value = value
		self.parent = None
		self.child_1 = None
		self.child_2 = None

	def add_child(self, data: str) -> 'TreeNode' or None:
		if data <= self.value:
			if self.child_1 is None:
				self.child_1 = TreeNode(data)
				self.child_1.set_parent(self)
				return self.child_1
			else:
				return self.child_1.add_child(data)
		elif self.child_2 is None:
			self.child_2 = TreeNode(data)
			self.child_2.parent = self
			return self.child_2
		else:
			return self.child_2.add_child(data)

	def set_child_1(self, data: str) -> 'TreeNode':
		self.child_1 = TreeNode(data)
		self.child_1.parent = self
		return self.child_1

	def set_child_2(self, data: str) -> 'TreeNode':
		self.child_2 = TreeNode(data)
		self.child_2.parent = self
		return self.child_2
		
	def remove_child(self, data: str) -> 'TreeNode' or None:
		if self.child_1 is not None and self.child_1.value == data:
			temp = self.child_1
			self.child_1 = None
		elif self.child_2 is not None and self.child_2.value == data:
			self.child_2 = None
			temp = self.child_2
		else:
			temp = None

		return temp

	def remove_child_1(self) -> None:
		self.child_1 = None

	def remove_child_2(self) -> None:
		self.child_2 = None

	def remove_children(self) -> None:
		self.child_1 = None
		self.child_2 = None

	def get_child(self, data: str) -> 'TreeNode':
		if self.child_1 is not None and self.child_1.value == data:
			return self.child_1
		elif self.child_2 is not None and self.child_2.value == data:
			return self.child_2

	def get_parent(self) -> 'TreeNode':
		return self.parent

	def get_value(self) -> str:
		return self.value

	def set_value(self, value: str) -> None:
		self.value = value

	def get_children(self) -> list:
		return [self.child_1, self.child_2]

	def get_child_1(self) -> 'TreeNode':
		return self.child_1

	def get_child_2(self) -> 'TreeNode':
		return self.child_2

	def get_descendants(self) -> list['TreeNode']:
		descendants = []
		if self.child_1 is not None:
			descendants.append(self.child_1)
			descendants.extend(self.child_1.get_descendants())
		if self.child_2 is not None:
			descendants.append(self.child_2)
			descendants.extend(self.child_2.get_descendants())
		return descendants

	def get_ancestors(self) -> list['TreeNode']:
		ancestors = []
		if self.parent is not None:
			ancestors.append(self.parent)
			ancestors.extend(self.parent.get_ancestors())

		return ancestors

	def __str__(self):
		return str(self.value)

	def set_parent(self, new_parent):
		self.parent = new_parent

