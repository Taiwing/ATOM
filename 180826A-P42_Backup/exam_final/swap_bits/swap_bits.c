
unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	ret;

	ret = 0;
	ret = octet >> 4 | octet << 4;
	return (ret);
}
