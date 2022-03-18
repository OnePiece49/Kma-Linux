             /*********************** FILE BÀI 3 ***********************/

BT3. Viết một chương trình có só lượng command-line arguments là 3, Có dạng như sau:
$ ./example_program filename num-bytes [r/w] "Hello"
Trong đó:
	1. example_grogram: Tên file thực thi
	2. filename: Tên file
	3. num-bytes: Số byte muốn read/write
	4. [r/w]: r -> Thực hiện đọc từ  filename và in ra màn hình
		    w -> Thực hiện ghi vào filename
	5. "Hello": Nội dung bất kì muốn read/write vào filename


Chú ý 1: Với ./main Huy Ngu Nhu Bo
    Thì tổng số arguments truyền vào là 5
         và argv[1] là "Huy", argv[2] là "Ngu"

Chú ý 2; Để chuyển từ string về int ta dùng hàm atoi();
    Vd: int byte_read = atoi(argv[2]);
	--> Hàm này trả về số nguyên đã được chuyển đổi dưới dạng một giá trị int. 
		Nếu không có sự chuyển đổi hợp lệ nào được thực hiện, hàm trả về 0.