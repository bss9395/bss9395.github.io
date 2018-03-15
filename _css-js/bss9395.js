"use strict";

window.onload = function () {
    /* images */
    function images() {
        var imgs = document.querySelectorAll("img");
        for (var i = 0; i < imgs.length; i++) {
        	if (imgs[i].alt !== "") {
        		imgs[i].style = imgs[i].alt;
        	}
        }
    }
    images();
};

/* search */
function searchAnything(value) {
    var input = value.replace(/(\s|»)+/igm, " ").toLowerCase();
    var tag = input.match(/^#\S+\s*/igm);
    var content = input.replace(tag, "");
    var section = document.getElementsByName("section");
    var i = 0,
        j = 0,
        dd;
    if (tag) {
        for (i = 0; i < section.length; i++) {
            var index = (section[i].textContent || section[i].innerText).replace(/(\s|»)+/igm, " ").toLowerCase().indexOf(tag);
            if (index === 1 || index === 0) {
                section[i].style.display = "";
                dd = section[i].getElementsByTagName("dd");
                if (content && content.length > 0) {
                    for (j = 0; j < dd.length; j++) {
                        if ((dd[j].textContent || dd[j].innerText).replace(/(\s|»)+/igm, " ").toLowerCase().indexOf(content) > -1) {
                            dd[j].style.display = "";
                        } else {
                            dd[j].style.display = "none";
                        }
                    }
                } else {
                    for (j = 0; j < dd.length; j++) {
                        dd[j].style.display = "";
                    }
                }
            } else {
                section[i].style.display = "none";
            }
        }
    } else {
        for (i = 0; i < section.length; i++) {
            if ((section[i].textContent || section[i].innerText).replace(/(\s|»)+/igm, " ").toLowerCase().indexOf(content) > -1) {
                section[i].style.display = "";
                dd = section[i].getElementsByTagName("dd");
                for (j = 0; j < dd.length; j++) {
                    if ((dd[j].textContent || dd[j].innerText).replace(/(\s|»)+/igm, " ").toLowerCase().indexOf(content) > -1) {
                        dd[j].style.display = "";
                    } else {
                        dd[j].style.display = "none";
                    }
                }
            } else {
                section[i].style.display = "none";
            }
        }
    }
}
