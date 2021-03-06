import java.io.RandomAccessFile;
import java.io.File;
import java.nio.channels.FileChannel;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.Pipe;
import java.nio.channels.Pipe.SinkChannel;
import java.nio.channels.Pipe.SourceChannel;


public class PipeToCopy
{
	Pipe pipe;
	SinkChannel sink;
	SourceChannel source;
	int size;
	public PipeToCopy() throws IOException
	{
		pipe = Pipe.open();	
		sink = pipe.sink();
		source = pipe.source();
		size=0;
	}	
	public void copyFromSrc(File file) throws IOException
	{
		FileChannel fc = new RandomAccessFile(file,"rw").getChannel();
		ByteBuffer buffer = ByteBuffer.allocate(1024);
		int val =0;
		while((val=fc.read(buffer))>0)
		{
			buffer.flip();
			sink.write(buffer);
			buffer.clear();
			System.out.println(val+"<--Read from source and written to sink");
		}
		fc.close();
		sink.close();
	}
	public void copyToDst(File file) throws IOException
	{
		FileChannel fc = new RandomAccessFile(file,"rw").getChannel();
		ByteBuffer buffer = ByteBuffer.allocate(1024);
		int val=0;
		while((val=source.read(buffer))>0)
		{
			buffer.flip();
			fc.write(buffer);
			buffer.clear();
			System.out.println(val+"<-- Read from source channel and written to dst");
		}
		source.close();
		fc.close();
	}
}

class PipeTester
{
	public static void main(String[] args) throws IOException
	{
		File src = new File(args[0]);
		File dst = new File(args[1]);
		PipeToCopy pipe = new PipeToCopy();
		pipe.copyFromSrc(src);
		pipe.copyToDst(dst);
	}
}
