                    /*********************** FILE BÀI 2 ***********************/

Đề bài: BT2. Sau mỗi lệnh write dưới đây, Cho biết nội dung sẽ được ghi vào file nào, nội dung là gì và giải thích tại sao?
    fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    fd3 = open(file, O_RDWR);
    write(fd1, "Hello,", 6);
    write(fd2, "world", 6);
    lseek(fd2, 0, SEEK_SET);
    write(fd1, "HELLO,", 6);
    write(fd3, "Gidday", 6);


                    /*********************** ĐÁP ÁN BÀI 2 ***********************/    
    fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        --> Tạo file với các cờ O_TRUNC nêu ở dưới và cấp quyền đọc ghi cho file qua cờ S_IRUSR(cờ đọc)) và S_IWUSR(cờ ghi).
    fd3 = open(file, O_RDWR);
        --> Mở file với phiên làm việc với quyền đọc ghi cho file đã tạo
        --> Chú ý: phiên làm việc là được đọc ghi, nhưng quyền cấp cho file không có đọc read và write thì cũng ko đọc ghi data được
    write(fd1, "Hello,", 6);
        --> Vì trong cùng một Process nên vẫn ghi data vào cuối file, và file chưa có dữ liệu nào nên data là "Hello"
    write(fd3, "world", 6);
        --> Ghi chèn bắt đầu từ đầu file, "Hello" bị ghi chèn bời "world", nên data trong file là "world".
    lseek(fd3, 0, SEEK_SET);
        --> Chuyển con trỏ trong file với fd3 về vị trí đầu tiên.
    write(fd1, "HELLO,", 6);
        -->Vì trong cùng một Process nên vẫn ghi data vào cuối file ứng với fd1, nên data trong file là "worldHello"
    write(fd3, "Gidday", 6);
        --> Vì con trỏ lúc này với fd3 ở vị trí đầu file nên nó sẽ ghi chèn lên "world" và data sẽ là "GiddayHello"

        --> Cuối cùng data trong file là "GiddayHello"


Chú ý 1: Khi mới tạo file và kết hợp luôn cờ O_TRUNC, thì file sẽ có quyền -r--r-x--- 
        --> Không có quyền write
    --> Để khắc phục vấn đề này, ta phải tạo FILE trước với không sử dụng cở O_TRUNC, rồi mở file lại với cờ O_TRUNC.
            -> Chú ý: Hai lần mở file này phải được mở ở 2 lần proceess, chứ ko được để 1 lần.
    --> Không thì ta cần cấp quyền cho file đó ở cmd.

Chú ý 2:  Khi khởi tạo với cờ đọc ghi, thì dữ liệu sau mỗi Process sẽ được ghi chèn ở đầu file.
        --> Còn trong cùng một Process, dữ liệu ghi lần sau sẽ được nối đuôi vào dữ liệu ghi ở lần trước.
    
Chú ý 3: Khi tạo File với cờ O_TRUNC thì trước khi ghi dữ liệu vào file, nó sẽ kiểm tra file đã
            tồn tại hay chưa, nếu có rồi thì dữ liệu trong file sẽ bị xóa hết rồi mới bắt đầu ghi.
        --> Chú ý: Trong cùng một Process thì khi ghi dữ liệu vào file khi có cờ O_TRUNC thì cũng sẽ được ghi vào tiếp tục ở cuối file
            --> Khi nào chạy Process khác thì nó mới bắt đầu kiểm tra xem file tồn tại chưa và xóa hết.

Chú ý 4: Hai cờ SET quyền đọc ghi cho file(permission) : S_IRUSR  và S_IWUSR ,... 
    -->  Như chú ý 1: Ta tạo file nhưng đôi khi file không được cấp quyền đúng theo ý muốn
        --> Ta sẽ tự cấp quyền với các bit permission ở thư viện #include <sys/stat.h>
            VD, Ta sẽ cấp quyền trực tiếp đọc ghi cho file mà không cần thông qua cmd:
                int fd = open(NAMEFILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR  );