'use strict';

window.onload = function () {
	/* images */
	function images() {
		var imgs = document.querySelectorAll('img');
		for (var i = 0; i < imgs.length; i++) {
			if (imgs[i].src.endsWith('.pdf')) {
				var a = document.createElement("a");
				a.href = imgs[i].src;
				a.innerHTML = imgs[i].src.substring(imgs[i].src.lastIndexOf('/') + 1);
				var obj = document.createElement("object");
				obj.type = "application/pdf";
				obj.data = imgs[i].src;
				obj.style = imgs[i].alt;
				obj.appendChild(a);
				imgs[i].parentNode.parentNode.replaceChild(obj, imgs[i].parentNode);
			} else {
				imgs[i].style = imgs[i].alt;
			}
		}
	}
	images();
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
