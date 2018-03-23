int f1(int);
static int f2(int);

int f1(int foo)
{
	return f2(foo);
}

int f2(int foo)
{
	return 42 + foo;
}
