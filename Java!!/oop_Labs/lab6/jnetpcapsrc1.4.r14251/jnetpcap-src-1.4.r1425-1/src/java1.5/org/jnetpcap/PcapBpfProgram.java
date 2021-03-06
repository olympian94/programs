/*
 * Copyright (C) 2005, 2006, 2007, 2008, 2009, 2010 Sly Technologies, Inc.
 *
 * This file is part of jNetPcap.
 *
 * jNetPcap is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as 
 * published by the Free Software Foundation, either version 3 of 
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package org.jnetpcap;

import java.nio.ByteBuffer;

import com.slytechs.library.JNILibrary;
import com.slytechs.library.Library;
import com.slytechs.library.LibraryInitializer;

// TODO: Auto-generated Javadoc
/**
 * <p>
 * Class peered with native <code>bpf_program</code> structure. Instance of a
 * compiled Berkley Packet Filter program. The program is an interpreted binary
 * byte program. Most modern unix and windows systems have a BPF interpreter
 * builtin and execute the code very efficiently, close to the source of the
 * capture and use the filter to permit or reject packets early.
 * </p>
 * <p>
 * <b>Special note:</b><br>
 * There also 2 private constructors which allow the object to be initialized in
 * Java space with a BPF program. The corresponding native C structures are
 * created and can be passed to <code>Pcap.setFilter</code> method. At this
 * time, the constructors are kept private for further testing. At some point
 * these private constructors will be made public and will allow outside filters
 * to be used with <em>Pcap</em> capture sessions.
 * 
 * @author Mark Bednarczyk
 * @author Sly Technologies, Inc.
 */
@Library(preload = { Pcap.class

}, jni = Pcap.LIBRARY)
public class PcapBpfProgram {

	/**
	 * Inits the i ds.
	 */
	@LibraryInitializer
	private native static void initIDs();

	static {
		JNILibrary.register(PcapBpfProgram.class);
	}

	/** Native address of the bpf_program C structure. */
	private volatile long physical = 0;

	/** The buffer. */
	private ByteBuffer buffer;

	/**
	 * Special constructor that allows creation of empty object ready for
	 * initialization. The object is only suitable for passing to Pcap.compile or
	 * Pcap.compileNoPcap which will initiliaze it. Using any of the getter
	 * methods before the PcapBpfProgram object is succesfully initialized will
	 * result in IllegalStateException being thrown.
	 * 
	 * @see Pcap#compile(PcapBpfProgram, String, int, int)
	 * @see Pcap#compileNoPcap(int, int, PcapBpfProgram, String, int, int)
	 */
	public PcapBpfProgram() {
		initPeer();
		buffer = null;
	}

	/**
	 * Allocates object's peered C structure bpf_program.
	 */
	private native void initPeer();

	/**
	 * Allocates a peering C structure and initializes it with data from the
	 * supplied buffer.
	 * 
	 * @param instructions
	 *          buffer containing BPF instructions
	 * @since 1.2
	 */
	public PcapBpfProgram(byte[] instructions) {
		buffer = null;

		if (instructions == null) {
			throw new NullPointerException("BPF instruction array is null");
		}

		if (instructions.length % 8 != 0) {
			throw new IllegalArgumentException(
					"Invalid BPF instruction buffer length. Must be a multiple of 8");
		}

		if (instructions.length == 0) {
			throw new IllegalArgumentException("BPF instruction array is empty");
		}

		initPeer();

		/*
		 * Allocate bpf_program structure in native memory and copy the byte array
		 */
		initFromArray(instructions);
	}

	/**
	 * Allocates a peering C structure and initializes it with data from the
	 * supplied buffer.
	 * 
	 * @param instructions
	 *          buffer containing BPF instructions
	 * @since 1.2
	 */
	public PcapBpfProgram(ByteBuf                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              