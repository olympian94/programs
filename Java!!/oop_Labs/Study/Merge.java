import java.io.*;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
class merge
{
	public static void main(String[] args) throws IOException
	{
		FileInputStream fin1 = new FileInputStream(args[0]);
		FileInputStream fin2 = new FileInputStream(args[1]);
		FileChannel fc1 = fin1.getChannel();
		FileChannel fc2 = fin2.getChannel();
		FileOutputStream fout = new FileOutputStream(args[2]);
		FileChannel fc_out = fout.getChannel();

//		ByteBuffer buffer = ByteBuffer.allocate(4096);
		ByteBuffer header = ByteBuffer.allocate(1024);
		ByteBuffer body   = ByteBuffer.allocate(3072);
		ByteBuffer[] bufferArray = { header, body };
//		fc.read(bufferArray);
		int read1 =fc1.read(header);
		int read2 =fc2.read(body); 
		while(read1>0||read2>0)
		{
			header.flip();
			body.flip();
			fc_out.write(bufferArray);
			header.clear();
			body.clear();
			read1=fc1.read(header);
			read2=fc2.read(body);

		}
		fc1.close();	
		fc2.close();	
		fc_out.close();
    }
}



