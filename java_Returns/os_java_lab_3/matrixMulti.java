class WorkerThread extends Thread{
    private int row;
    private int col;
    private int dimensionM;
    private int [][] A;
    private int [][] B;
    private int [] products;
    private int sum;

    public WorkerThread(int row, int col, int[][] A, int[][] B, int dimensionM)
    {
        this.row = row;
        this.col = col;
        this.A = A;
        this.B = B;
        this.dimensionM = dimensionM;
        products = new int[dimensionM];
    }
    
    public void run() {
        //C[row][col] = (A[row][0] * B[0][col])+ (A[row][1]*B[1][col]) ; 
        for(int i=0; i<dimensionM; i++)
        	products[i] = A[row][i] * B[i][col];

    }   

    public int addProducts(){
    	
    	for(int j=0; j<dimensionM; j++)
    		sum+=products[j];
    	return sum;
    }
}

public class matrixMulti {

    //initializes variables for dimensions
    public static int M = 5;
    public static int K = 5;
    public static int N = 5;
    
    //Declares Arrays A,B,C, and an Array or WorkerThreads
    public static int [][] A = {{1,0,0,0,0}, {0,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,0}, {0,0,0,0,1}}; //Initializes A
    public static int [][] B = {{1,2,3,4,5}, {1,3,0,2,0}, {1,0,0,4,0}, {1,0,3,0,0}, {1,5,0,0,9}}; //Initializes B
    public static int [][] C = new int [M][N];
    public static WorkerThread [][] Threads = new WorkerThread[M][N];
    
    
    public static void main(String[] args) {      
        //creates 9 Worker threads. Each thread Calculates a Matrix Value and sets it to C matrix
        for (int i = 0; i<M; i++){
            for (int j=0; j<N; j++){
                Threads[i][j] = new WorkerThread(i,j,A,B,K);
                Threads[i][j].start();
            }
        }
        
        //wait for multiplications to complete
        try{
        	for (int i = 0; i<M; i++){
	            for (int j=0; j<N; j++){
                	Threads[i][j].join();
            	}
        	}
        }
        catch(InterruptedException e){ e.printStackTrace();}

        //do the addition of values
        for (int i = 0; i<M; i++){
            for (int j=0; j<N; j++){
            	C[i][j]=Threads[i][j].addProducts();
            }
        }


        //Outputs the Values of Matrix C
        System.out.println("Elements of Matrix C:");
        for (int i = 0; i<M; i++){
            for (int j=0; j<N; j++){
                System.out.print("["+i+","+j+"] = "+C[i][j]+ "   ");
            }
            System.out.println("\n");
        }  
    }
}