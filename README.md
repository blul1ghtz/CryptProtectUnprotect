========== CRYPT PROTECT AND CRYPT UNPROTECT ==========

Crypt protect and crypt unprotect are two function created
by windows to encrypt and decrypt data, once data is encrypted
it must be decrypted on the same device. (or very special 
cirumstances)

This program takes the string of your choice and creates a
DATA_BLOB variable for it and assigns it the string value and
its size for later decrypting, then we create another DATA_BLOB
variable to store the decrypted data, CryptProtect's magic is
done and the data is output to the second DATA_BLOB.pbData variable
along with its size to .cbData.

Now for decrypting you pass in a DATA_BLOB and the CryptUnprotet
function will crerate a DATA_BLOB variable for decrypted variable
like before, this time the decrypted value will be outputted to the
created DATA_BLOB.

There are also points at which the program will print the blobs info.
