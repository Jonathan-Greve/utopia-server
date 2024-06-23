import mmap
import struct
import os
import shutil

def find_pattern(mm, pattern):
    return mm.find(pattern)

def read_dhk(file_path):
    with open(file_path, 'rb') as f:
        root = f.read(4)
        prime = f.read(64)
        public_key = f.read(64)
    return root, prime, public_key

def reverse_bytes(data):
    return bytes(reversed(data))

def patch_file(original_exe_path, patched_exe_path, dhk_path):
    # Read the DHK components
    root, prime, public_key = read_dhk(dhk_path)
    
    # Create a copy of the original executable
    shutil.copy2(original_exe_path, patched_exe_path)
    
    # Open the new executable file in read/write binary mode
    with open(patched_exe_path, 'r+b') as f:
        # Memory-map the file
        mm = mmap.mmap(f.fileno(), 0)
        
        # Define the byte pattern to search for
        pattern = b'\x8b\x45\x08\xc7\x00\x88\x00\x00\x00\xb8'
        
        # Find the pattern
        offset = find_pattern(mm, pattern)
        
        if offset == -1:
            print("Pattern not found.")
            mm.close()
            os.remove(patched_exe_path)  # Remove the copied file if patching fails
            return
        
        # The address we're looking for is 4 bytes after the pattern
        address_offset = offset + len(pattern)
        
        # Read the 4-byte address
        address_bytes = mm[address_offset:address_offset+4]
        address = struct.unpack('<I', address_bytes)[0]
        
        print(f"Found address: 0x{address:08x}")
        
        # Calculate the file offset, considering the base address
        text_section_offset = 0x1000
        rdata_section_offset = 0x800
        base_address = 0x00400000 + text_section_offset + rdata_section_offset
        file_offset = address - base_address
        
        print(f"Calculated file offset: 0x{file_offset:08x}")
        
        # Seek to the file offset and skip the first 4 bytes
        mm.seek(file_offset + 4)
        
        # Write the root in big-endian
        mm.write(reverse_bytes(root))
        
        # Write the prime and public key in big-endian (132 bytes total)
        mm.write(reverse_bytes(prime))
        mm.write(reverse_bytes(public_key))
        
        print("DHK patched successfully.")
        
        # Close the memory-map
        mm.close()

# Paths
original_exe_path = 'C:/games/GW/Guild Wars/Gw.exe'
patched_exe_path = 'C:/games/GW/Guild Wars/PatchedGw.exe'
dhk_path = 'data/gw_key/public_gw_key'

# Run the patching process
patch_file(original_exe_path, patched_exe_path, dhk_path)

print(f"Patched executable created at: {patched_exe_path}")