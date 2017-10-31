public class MyMain
{
	static int testNum = 5;

    public static void main(String[] args) 
    {

        MainSolve mainSolve = new MainSolve();
        
        // my init
        mainSolve.myInit(args);

        // my solve
        for(int mainI=0; mainI<testNum; mainI++) 
        {	
            // use a certain vertex whose id is mainI to do the exploration	
			mainSolve.mySolve(args, mainI);
		}

        System.out.println("finished");  
    }
}
