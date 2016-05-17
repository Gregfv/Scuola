char aBase64(int n){
	if(n <= 25) return 'A' + n;
	if(n <= 51) return n - 26 + 'a';
	if(n <= 61) return n  - 52 + '0';
	if(n == 62) return '+';
	if(n == 63) return '/';
}
