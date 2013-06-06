<?php

/**
 * Administration form for moot.
 */
function moot_admin_form() {

  $entities = entity_get_info();
  
  // Unless someone has a good use case for this, remove comments from the entities list.
  unset($entities['comment']);
    
  $form['moot_forum_title'] = array(
    '#type' => 'textfield',
    '#title' => t("Moot Forum Title"),
    '#description' => t("The forum name is the first part of the URL after http://moot.it/"),
    '#default_value' => variable_get('moot_forum_title', ''),
    '#required' => TRUE
  );

  $form['moot_comment_style'] = array(
    '#type' => 'radios',
    '#title' => t('Comment Style'),
    '#options' => array(
      'threaded' => t('Threaded'),
      'flat' => t('Flat'),
    ),
    '#default_value' => variable_get('moot_comment_style', 'threaded')
  );
  
  $entity_type_settings = variable_get('moot_comment_entity_types', array());
  $form['moot_comment_entity_types'] = array(
    '#type' => 'fieldset',
    '#title' => t('Entity Type Settings'),
    '#collapsible' => FALSE,
    '#tree' => TRUE,
  );
  
  foreach($entities as $entity_name => $entity) {
    
    $bundles = array();
    foreach($entity['bundles'] as $bundle_name => $bundle) {
      $bundles[$bundle_name] = $bundle['label'];
    }

    $form['moot_comment_entity_types'][$entity_name] = array(
      '#type' => 'fieldset',
      '#title' => $entity['label'],
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    
    $form['moot_comment_entity_types'][$entity_name]['bundles'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Enable Moot commenting for @types types', array('@types' => ucwords($entity['label']))),
      '#options' => $bundles,
      '#default_value' => isset($entity_type_settings[$entity_name]['bundles']) ? isset($entity_type_settings[$entity_name]['bundles']) : array()
    );
  }
  
  /*
  $form['moot_comment_entity_types'] = array(
    '#type' => 'checkbox',
    '#title' => t("Moot Commenting Entity Types")
  );
  /**/
  
  return system_settings_form($form);
}

/**
 * Set up some sensible defaults for the moot_content_entity_types admin form setting.
 */
function _moot_comment_entity_types_defaults($entity_type = NULL) {
  
}
