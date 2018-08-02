## 更新Next



所有文档均保存在~/blog/_data/目录中

首先运行`npm install`

* Next主题next.yml重新添加到_config.yml

* 将404.html添加到themes/source中

* 将\_layout.swig中的24行至26行和94至95行添加到themes/next/layout/_layout.swig

* 将love.js复制到themes/next/source/js/src中

* 在themes/next/layout/_macro/post.swig搜索`rel="tag">#`，将#替换成`<i class="fa fa-tag"></i>`

* 在themes/next/layout/_partials/footer.swig中第一行添加`<script async src="https://dn-lbstatics.qbox.me/busuanzi/2.3/busuanzi.pure.mini.js"></script>`

  第26行添加

  ```js
  <div class="powered-by">
  <i class="fa fa-user-md"></i><span id="busuanzi_container_site_pv">
    本站访客数:<span id="busuanzi_value_site_pv"></span>
  </span>
  </div>
  ```

  末尾添加

  ```js
  <div class="theme-info">
    <div class="powered-by"></div>
    <span class="post-count">博客全站共{{ totalcount(site) }}字</span>
  </div>
  ```

  将第32行至55行注释

* 在根目录下运行`npm install hexo-wordcount --save`

* 在站点根目录下运行`npm install gulp -g`和`npm install gulp-minify-css gulp-uglify gulp-htmlmin gulp-htmlclean gulp --save`

* 打开/themes/next/source/css/_custom/custom.styl，添加

  ```styl
  // 主页文章添加阴影效果
   .post {
     margin-top: 60px;
     margin-bottom: 60px;
     padding: 25px;
     -webkit-box-shadow: 0 0 5px rgba(202, 203, 203, .5);
     -moz-box-shadow: 0 0 5px rgba(202, 203, 204, .5);
    }
  ```

* 打开/themes/next/layout/_partials/head.swig，在第四行添加

  ```swig
  <script src="//cdn.bootcss.com/pace/1.0.2/pace.min.js"></script>
  <link href="//cdn.bootcss.com/pace/1.0.2/themes/pink/pace-theme-flash.css" rel="stylesheet">
  ```

以上便可以完成大部分工作

