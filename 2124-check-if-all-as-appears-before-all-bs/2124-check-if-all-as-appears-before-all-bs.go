func checkString(s string) bool {
    for i := 1; i < len(s) ; i++{
        if s[i] == 'a'{
            if s[i - 1] == 'b'{return false;}
        }
    }
    return true;
}