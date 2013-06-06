(function($) {

/**
 * Live preview of Administration menu components.
 */
Drupal.behaviors.moot = {
  attach: function(context, settings) {
	  var mootBaseUrl = 'http://moot.it';
	  var forumName = Drupal.settings.moot.forumName;
	  var contentUrl = Drupal.settings.moot.contentUrl;
	  var contentTitle = Drupal.settings.moot.contentTitle;
	  var forumUrl = mootBaseUrl + '/i/' + forumName;

	  var mootWrapper = $('<div>').addClass('moot').moot({
	    'url': forumUrl + contentUrl,
	    'title': contentTitle
	  });
	  
	  $('.node').after($(mootWrapper));
  }
}

})(jQuery);
