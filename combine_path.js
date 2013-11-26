function combine_path(pwd, path) {
    if(path == "") {
        return pwd;
    }
    if(path.indexOf('/') == 0) {
        return combine_path(path, "");
    }
    if(path[0] != '.') {
        path = "./" + path;
    }
    pwdParts = pwd.split('/').concat(path.split('/'));
    console.log(pwdParts);
    resolvedParts = [];
    pwdParts.forEach(function(val, index) {
        if(val == '..') {
            resolvedParts.pop();
        } else if (val != '.' && val != '') {
            resolvedParts.push(val);
        }
    });
    return  '/' + resolvedParts.join('/');
}

console.log(combine_path("/abc/d", "explicitly/relative/with/../corrections"));