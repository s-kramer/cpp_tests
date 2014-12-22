int main()
{
    const auto i = 5;
    // This doesn't compile because the cv-qualifieness of the local variable is preserved in the lambda capture when passed by value!
    auto f = [i]() { i = 15; };

    return 0;
}
