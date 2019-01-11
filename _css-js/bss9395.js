'use strict';

window.onload = function () {
    /* images */
    function IMAGE() {
        var imgs = document.querySelectorAll('img');
        var pdfs = document.querySelectorAll('img[src$=".pdf"]');
        for (var i = 0; i < imgs.length; i++) {
            imgs[i].style = imgs[i].alt;
        }
        for (var i = 0; i < pdfs.length; i++) {
            var a = document.createElement('a');
            a.href = pdfs[i].src;
            a.innerHTML = pdfs[i].src.substring(pdfs[i].src.lastIndexOf('/') + 1);
            var obj = document.createElement('object');
            obj.type = 'application/pdf';
            obj.data = pdfs[i].src;
            obj.style = pdfs[i].alt;
            obj.appendChild(a);
            pdfs[i].parentNode.parentNode.replaceChild(obj, pdfs[i].parentNode);
        }
    }
    IMAGE();

    /* mathjax */
    function MATH() {
        var maths = document.querySelectorAll('div>pre>code');
        for (var i = 0; i < maths.length; i++) {
            var section = document.createElement('section');
            section.innerHTML = maths[i].innerHTML;
            maths[i].parentNode.parentNode.replaceWith(section);   
            MathJax.Hub.Queue(['Typeset', MathJax.Hub, section]);
        }
    }
    MATH();
};

/* search */
function searchAnything(value) {
    var input = value.replace(/(\s|»)+/igm, ' ').toLowerCase();
    var tag = input.match(/^#\S+\s*/igm);
    var content = input.replace(tag, '');
    var dl = document.getElementsByTagName('dl');
    var i = 0,
        j = 0;
    if (tag) {
        for (i = 0; i < dl.length; i++) {
            var dt = dl[i].getElementsByTagName('dt');
            var index = (dt[0].textContent || dt[0].innerText).replace(/(\s|»)+/igm, ' ').toLowerCase().indexOf((tag + '').replace('#', ''));
            if (index > -1) {
                dl[i].style.display = '';
                var dd = dl[i].getElementsByTagName('dd');
                if (content && content.length > 0) {
                    for (j = 0; j < dd.length; j++) {
                        if ((dd[j].textContent || dd[j].innerText).replace(/(\s|»)+/igm, ' ').toLowerCase().indexOf(content) > -1) {
                            dd[j].style.display = '';
                        } else {
                            dd[j].style.display = 'none';
                        }
                    }
                } else {
                    for (j = 0; j < dd.length; j++) {
                        dd[j].style.display = '';
                    }
                }
            } else {
                dl[i].style.display = 'none';
            }
        }
    } else {
        for (i = 0; i < dl.length; i++) {
            if ((dl[i].textContent || dl[i].innerText).replace(/(\s|»)+/igm, ' ').toLowerCase().indexOf(content) > -1) {
                dl[i].style.display = '';
                var dd = dl[i].getElementsByTagName('dd');
                for (j = 0; j < dd.length; j++) {
                    if ((dd[j].textContent || dd[j].innerText).replace(/(\s|»)+/igm, ' ').toLowerCase().indexOf(content) > -1) {
                        dd[j].style.display = '';
                    } else {
                        dd[j].style.display = 'none';
                    }
                }
            } else {
                dl[i].style.display = 'none';
            }
        }
    }
}
