# get_next_line
With this project I create a function get_next_line() which would let us read the text file pointed to by the file descriptor, one line at a time as per it's multiple calls.
The bonus function is same as main function except it can manage multiple file descriptors at the same time. i.e it is able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd.
