class Attrb
{
	private final String name;
	private Object value = null;
	public Attrb(String nm)
	{	name=nm;	}
	public Attbr(String, nm, Object val)
	{	name=nm;	value=val;	}
	public String getname()
	{	return name;	}
	public Object getval()
	{	return value;	}
	public void setvalue(Object val)
	{	value=val;		}
	public String toString()
	{	return name + " = " + value + " ; ";	}
}
class ColorAttrb extends Attrb
{
	private ScreenColor mycolor;
	public ColorAttrb(String name, Object value)	
	{
		super(name,value);	
		decodeColor();
	}
	public ColorAttrb(String name)
	{
		this(name,"transparent");
	}
	public ColorAttrb(String name, ScreenColor value)
	{
		super(name,value.toString());
		mycolor = value;	
	}
	public object setvalue(Object val)
	{
		super.setvalue(val);
		decodeColor();
	}
	public void setvalue(ScreenColor val)
	{
		super.setvalue(val.toString());
		mycolor=val;
	}
	public ScreenColor getcolor()
	{	return mycolor;	}
	protected void decodeColor()	
	{
		if(getval==null)
			mycolor=null;
		else
			mycolor = new ScreenColor(getval());
	}
	
}