import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PipeDemoMain {
	public static void main(String argv[]) throws IOException, FileNotFoundException {
		
		FileReader fr = new FileReader("source.txt");
		FileWriter fw = new FileWriter("destination.txt");
		
		PipeDemo pipe_demo = new PipeDemo();
		
		pipe_demo.copySrc(fr);
		pipe_demo.copyDst(fw);
		
	}	
}