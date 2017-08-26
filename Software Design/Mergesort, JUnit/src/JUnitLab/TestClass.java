package JUnitLab;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class TestClass {
	@Test
    public void testInOrder()
    {
         Integer [] TestArray = new Integer[] {1,3,2};
         Integer [] CorrectArray = new Integer[] {1,2,3};
         MergeSort.mergeSort(TestArray);
         assertTrue(CompareArrays(TestArray, CorrectArray));
     }

	private boolean CompareArrays(Integer[] testArray, Integer[] correctArray) {
		boolean b = true;
        if (testArray != null && correctArray != null){
        	if (testArray.length != correctArray.length){
        		b = false;
        	} else {
        		for (int i = 0; i < correctArray.length; i++) {
        			if (testArray[i] != correctArray[i]) {
        				b = false;    
        			}
        		}
        	}
        }else{
        	b = false;
        }
		return b;
	}
}
