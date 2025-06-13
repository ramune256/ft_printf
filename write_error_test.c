#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

void test_write_failure()
{
    printf("=== Testing write failure ===\n");

    // 標準出力を閉じる
    close(1);

    // この時点でft_printfのwriteは失敗する
    int result = ft_printf("This should fail: %d\n", 42);

    fprintf(stderr, "ft_printf returned: %d\n", result);

    if (result == -1)
        fprintf(stderr, "SUCCESS: Error was properly detected!\n");
    else
        fprintf(stderr, "FAILURE: Error was not detected properly!\n");
}

int main()
{
    test_write_failure();
    return 0;
}
