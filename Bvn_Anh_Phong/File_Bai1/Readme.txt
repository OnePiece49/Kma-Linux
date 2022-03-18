                    /*********************** FILE BÀI 1 ***********************/

Đề bài:  Viết một chương trình mở một file bất kì và sử dụng cờ O_APPEND, sau đó thực hiện seek về đầu file 
    rồi ghi một vài dữ  liệu vào file đó. Dữ liệu sẽ xuất hiện ở vị trí nào của file và tại sao lại như vậy?


Chú ý 1: Khi mới tạo file và kết hợp luôn cờ O_APPEND, thì file sẽ có quyền -r--r-x--- 
        --> Không có quyền write
    --> Để khắc phục vấn đề này, ta phải tạo FILE trước với không sử dụng cở O_APPEND, rồi mở file lại với cờ O_APPEND.
            -> Chú ý: Hai lần mở file này phải được mở ở 2 lần proceess, chứ ko được để 1 lần.
    --> Không thì ta cần cấp quyền cho file đó ở cmd.

Chú ý 2:  Khi khởi tạo với cờ đọc ghi, thì dữ liệu sau mỗi Process sẽ được ghi chèn ở đầu file.
        --> Còn trong cùng một Process, dữ liệu ghi lần sau sẽ được nối đuôi vào dữ liệu ghi ở lần trước.
    
Chú ý 3: Khi tạo File với cờ O_APPEND thì dữ liệu khi ta ghi vào File sẽ được nối đuôi nhau chứ ko ghi chèn vào đầu file
            như ở cờ đọc ghi.

Chú ý 4: Khi ta kết hợp với cờ O_APPEND thì kể cả ta sử dụng hàm lseek() để truyển con trỏ về đầu file() 
            Vd: lseek(fd, 0, SEEK_SET); thì kể cả thế dữ liệu vẫn sẽ được ghi ở cuối file
                và hàm lseek() ở đây chỉ có tác dụng là ta sẽ đọc dữ liệu từ vị trí nào.
    -> Cờ O_APPEND được sử dụng cho mục đích của nhiều Process nối thêm "văn bản" vào tệp.

Chú ý 5: Khi không sử dụng hàm lseek() thì kho read data, nó sẽ auto đọc dữ liệu bắt đầu từ vị trí đầu file.
    --> Khi sử dụng hàm lseek() thì dữ liệu ta sẽ đọc ở vị trí ta chỉ định
    Vd Hàm lseek(), --> Đọc data ở vị trí sau byte đầu tiên 4 byte
                    lseek(fd, 4, SEEK_SET);
