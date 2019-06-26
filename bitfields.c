


//Bitfields demo

#include <stdio.h>
#include <string.h>
#include <unistd.h>


struct 
{
	int member1;
	int member2;
} d1;

struct 
{
	int member1 : 3;
	int member2 : 1;
} d2;

void	print_bits(unsigned char octet)
{
	d1.member2 |= 1 << 0;
	d1.member2 |= 1 << 4;
	int i;
	unsigned char bit;

	i = 8;
	while(i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}


int		main()
{
	int bit;
	int bit2;
// there will be 8 bytes taken since each int is 4 bytes and theres two members
	//printf("size of regular structure = %lu\n", sizeof(d1));
	//printf("size of structure with bit field = %lu\n", sizeof(d2));
	printf("Setting bits:\n");
	printf("d1.member2 |= 1 << 4\n");
	printf("d1.member2 |= 1 << 0");
	printf("\n\n");
	d1.member2 |= 1 << 4;
	d1.member2 |= 1 << 0;
	printf("d1.member2 = ");
	printf("\n");
	print_bits(d1.member2);
	printf("\n\n");

	printf("Checking bit state...\n");
	bit = (d1.member2 >> 4) & 1;
	bit2 = (d1.member2 >> 8) & 1;
	printf("The bit state for the 4th index is: %d\n", bit);
	printf("The bit state for the 8th index is: %d\n", bit2);
	printf("\n");
	print_bits(d1.member2);
	printf("\n");


	printf("Clearing bits:\n");
	d1.member2 &= ~(1 << 0);
	printf("d1.member2 = ");
	printf("\n");
	print_bits(d1.member2);
	printf("\n");
	d1.member2 &= ~(1 << 0);
	printf("\n");



	printf("Toggle (0)th bit:\n");
	printf("BEFORE:\n");
	printf("\n");
	d1.member2 ^= (1 << 0);
	print_bits(d1.member2);
	printf("\n");
	printf("AFTER:\n");
	printf("\n");
	d1.member2 ^= (1 << 0);
	print_bits(d1.member2);
	printf("\n");



//	&= ~
	return (0);
}
