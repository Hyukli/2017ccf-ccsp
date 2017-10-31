class MainSolve 
{
	// your code
	// you can add variables and functions as you need
    
    void myInit(String[] args) 
    {
    	// your code
		// you should delete next 3 lines
    	MainOutput myOutput = new MainOutput();
    	myOutput.mainOutput(1,1,1);
    	System.out.println("This is myInit()");  
    }
    
    void mySolve(String[] args, int beginVertex) 
    {
    	// your code
        // please use MainOutput.mainOutput() to output your result	
    	// you should delete next 3 lines
    	MainOutput myOutput = new MainOutput();
    	myOutput.mainOutput(beginVertex,beginVertex,beginVertex);
    	System.out.println("This is mySolve()"); 
    }
}
