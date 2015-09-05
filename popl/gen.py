def lengen(len):
	
	if len>0 :
		for ch in ['a','b','c','d']:
			for w in lengen(len-1):
				yield ch+w

for word in lengen(3):
	print word
