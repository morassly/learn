package leetcode

func reverseBits(num uint32) uint32 {
	var ans uint32
	for i := 0; i < 32; i++ {
		ans <<= 1
		ans |= num & 1
		num >>= 1
	}
	return ans
}

const (
	a = 0x55555555
	b = 0x33333333
	c = 0x0f0f0f0f
	d = 0x00ff00ff
)

func reverseBits1(num uint32) uint32 {
	num = num&a<<1 | num>>1&a
	num = num&b<<2 | num>>2&b
	num = num&c<<4 | num>>4&c
	num = num&d<<8 | num>>8&d
	return num<<16 | num>>16
}
