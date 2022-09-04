func reverse(x int) int {
	const max = 2147483647
	const min = -2147483648
	r := 0
	for x != 0 {
		c := 10*r + x%10
		if c > max || c < min {
			return 0
		}
		r = c
		x /= 10
	}
	return r
}
