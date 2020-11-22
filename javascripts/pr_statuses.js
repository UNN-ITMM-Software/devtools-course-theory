function github_api_get(url, callback) {
  $.ajax({
    url: url,
    dataType: 'json',
  })
  .done((res, status, request) => {
    let data = res;
    let headers_link = request.getResponseHeader('link');

    if (headers_link) {
      var next_page = undefined;
      headers_link.split(', ').forEach((link) => {
        if (link.endsWith('rel="next"')) {
          url = link.substr(1, link.indexOf('>') - 1);
          next_page = url;
        }
      });
      if (next_page) {
        github_api_get(next_page, (page_data) => {
          data = data.concat(page_data)
          callback(data);
        });
      } else {
        callback(data);  // This is last page
      }
    } else {
      callback(data);  // Data is represented as a single page
    }
  });
}

function list_pull_requests() {
  let prefix = 'https://api.github.com/repos/UNN-ITMM-Software/devtools-course-practice';
  github_api_get(prefix + '/pulls?per_page=100&state=all', (pulls) => {
    let table = document.getElementById("pull_requests_table");
    table.innerHTML = "";

    let pr_by_user = new Map();
    pulls.forEach((pull) => {
      var user = pull.user.login;
      if (!pr_by_user.has(user)) {
        pr_by_user.set(user, []);
      }
      pr_by_user.get(user).push(pull);
    });

    let max_num_cells = Array.from(pr_by_user.values()).reduce((max_num_cells, entry) => {
      return Math.max(entry.length, max_num_cells)
    }, 0);

    pr_by_user.forEach((pulls, user) => {
      let row = table.insertRow(-1);
      row.insertCell(-1).innerHTML = "<a href=https://github.com/" + user + ">" + user + "</a>";
      pulls.forEach((pull) => {
        var html = "<a href=" + pull.html_url + "><img src='https://img.shields.io/badge/";
        if (pull.merged_at) {
          html += "-merged-purple";
        } else if (pull.closed_at) {
          html += "-closed-red";
        } else {
          html += "-open-4BC51D";
        }
        row.insertCell(-1).innerHTML = html + "?style=plastic'/></a>";
      });
      for (let i = pulls.length; i < max_num_cells; ++i) {
        row.insertCell(-1);
      }
    });
  });
}

list_pull_requests();
