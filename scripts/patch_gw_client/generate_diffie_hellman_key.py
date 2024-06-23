import os
from cryptography.hazmat.primitives.asymmetric import dh
from cryptography.hazmat.primitives import serialization

def int_to_bytes(x: int, length: int) -> bytes:
    return x.to_bytes(length, byteorder='big')

def generate_diffie_hellman_keys():
    # Create the output directory if it doesn't exist
    output_dir = "data/gw_key"
    os.makedirs(output_dir, exist_ok=True)

    # Set the primitive root to 4
    g = 4

    # Generate a large prime p
    parameters = dh.generate_parameters(generator=2, key_size=512)
    p = parameters.parameter_numbers().p

    # Generate private key (random number x)
    x = int.from_bytes(os.urandom(64), byteorder='big') % (p - 2) + 2

    # Compute public key y = g^x mod p
    y = pow(g, x, p)

    # Convert to bytes
    primitive_root = int_to_bytes(g, 4)
    prime_modulus = int_to_bytes(p, 64)
    server_public = int_to_bytes(y, 64)
    server_private = int_to_bytes(x, 64)

    # Write public key components to public_gw_key file
    with open(os.path.join(output_dir, 'public_gw_key'), 'wb') as public_file:
        public_file.write(primitive_root)
        public_file.write(prime_modulus)
        public_file.write(server_public)

    # Write private key to private_gw_key file
    with open(os.path.join(output_dir, 'private_gw_key'), 'wb') as private_file:
        private_file.write(server_private)

    print("Keys generated and saved to 'scripts/patch_gw_client/public_gw_key' and 'scripts/patch_gw_client/private_gw_key'.")

if __name__ == "__main__":
    generate_diffie_hellman_keys()