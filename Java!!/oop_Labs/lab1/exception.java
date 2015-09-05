public Object pop()
{
	Object obj;
	if(size==0)
		throw new EmptyStackException();
	obj=ObjectAt(size-1);
	setObjectAt(size-1,null);
	size--;
	return obj;
}

public double[] getDataSet(String setName)
throws BadDataSetException
{
	String file = setName + ".dset";
	FileInputStream in = null;
	try {
		in = new FileInputStream(file);
		return readDataSet(in);
	} catch (IOException e) {
		throw new BadDataSetException();
	} finally {
		try {
			if (in != null)
		in.close();
	} catch (IOException e) {
			;
// ignore: we either read the data OK
// or we're throwing BadDataSetException
		}
	}
}
// ... definition of readDataSet ...
}
