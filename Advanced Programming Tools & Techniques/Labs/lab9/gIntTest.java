//Test the gInt class methods
//Author: Alan Tsai
//5/29/16

import junit.framework.*;

public class gIntTest extends TestCase {
	
	public static void main( String[] args )
	   {
		 String[] caseName = { gIntTest.class.getName() };
		 junit.textui.TestRunner.main( caseName );
		}

	 private gInt x;
	 private gInt y;
	 private gInt z;
	 private gInt w;
	 private gInt a;
	 private gInt b;

	//Constructor for gIntTest
	public gIntTest( String name)
	{
		super(name);
	}
   //Test cases
	protected void setUp()
	{
		x = new gInt(2,3);
		y = new gInt(2,-3);
		z = new gInt(-2, 3);
		w = new gInt(-2, -3);
		a = new gInt(3,4);
		b = new gInt(9,16);
	}
	
	//Add method test
	public void AddTest()
	{
		gInt result = x.add(a);
		Assert.assertEquals(result, new gInt(5,7));
	}
	
	//Multiply method test
	public void MultTest()
	{
		gInt result = a.multiply(b);
		Assert.assertEquals(result, new gInt(-37,84));
	}
	
	//norm mehtod test
	public void NormTest()
	{
		float expected = 5;
		float result = a.norm();
		Assert.assertEquals(expected, result);
	}
	
	//create test suite
	public static Test suite()
	{
		TestSuite suite = new TestSuite();
		suite.addTest(new gIntTest( "AddTest" ));
		suite.addTest(new gIntTest( "MultTest" ));
		suite.addTest(new gIntTest( "NormTest" ));
		return suite;
	}
}
